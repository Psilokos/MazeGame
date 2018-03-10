#include <dlfcn.h>
#include <core_Plugin.hpp>

namespace core
{
    Plugin::Plugin(std::string const & type) :
        m_type(type)
    {
        // loop on plugins in plugin list
            // if type_in_list == type
                // int r = load(plugin_path);
    }

    Plugin::~Plugin(void)
    {
        (*m_fp_unload)(this);
    }

    void *
    Plugin::instance(void) const
    {
        return m_instance;
    }

    void
    Plugin::instance(void * instance)
    {
        m_instance = instance;
    }

/*
** private methods
*/

    int
    Plugin::load(std::string const & filename)
    {
        void * handle = dlopen(filename.c_str(), RTLD_LAZY); // use dlmopen with linker namespaces dictionnary (string(type), int(id))
        if (!handle)
            return 1; // enum for error handling

        int (*fp_load)(void *) = dlsym(handle, "Load");
        int r = (*fp_load)(this);
        if (!r)
            m_fp_unload = dlsym(handle, "Unload");
        return r;
    }
}
