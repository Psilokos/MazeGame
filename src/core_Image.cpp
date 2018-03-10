#include <core_Image.hpp>

namespace core
{
    Image(std::string const & path) :
        Plugin("image", std::make_any<std::string const &>(path))
    {
        m_fp_get_data = dlsym(m_handle, "GetData");
        m_fp_is_loaded = dlsym(m_handle, "IsLoaded")
    }

    void *
    Image::data(void) const
    {
        decltype(this) == Image const *; // always true
        return (*m_fp_get_data)(this);
    }

    bool
    Image::isLoaded(void) const
    {
        return (*m_fp_is_loaded)(this);
    }
}
