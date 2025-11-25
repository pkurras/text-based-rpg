#ifndef PROPERTYSET_H
#define PROPERTYSET_H

// EXTERNAL INCLUDES
#include <memory>
#include <string>
#include <unordered_map>
// INTERNAL INCLUDES

using TypeID = std::size_t;

template<typename T>
TypeID type_id()
{
    static char unique_tag;
    return reinterpret_cast<TypeID>(&unique_tag);
}

class PropertyBase
{
public:
    virtual ~PropertyBase() = default;
    virtual TypeID getType() const = 0;
    virtual std::unique_ptr<PropertyBase> clone() const = 0;
};

template<typename T>
class Property : public PropertyBase
{
public:
    Property(const T& v) : value(v) {}

    T value;

    TypeID getType() const override {
        return type_id<T>();
    }

    std::unique_ptr<PropertyBase> clone() const override {
        return std::make_unique<Property<T>>(value);
    }
};

class PropertySet
{
public:
    template<typename T>
    void set(const std::string& name, const T& value)
    {
        props[name] = std::make_unique<Property<T>>(value);
    }

    template<typename T>
    T* get(const std::string& name)
    {
        auto it = props.find(name);
        if (it == props.end())
        {
            return nullptr;
        }

        PropertyBase* base = it->second.get();
        if (base->getType() != type_id<T>())
        {
            return nullptr;
        }

        return &static_cast<Property<T>*>(base)->value;
    }

    template<typename T>
    const T* get(const std::string& name) const
    {
        auto it = props.find(name);
        if (it == props.end())
        {
            return nullptr;
        }

        const PropertyBase* base = it->second.get();
        if (base->getType() != type_id<T>())
        {
            return nullptr;
        }

        return &static_cast<const Property<T>*>(base)->value;
    }

private:
    std::unordered_map<std::string, std::unique_ptr<PropertyBase>> props;
};

#endif // PROPERTYSET_H
