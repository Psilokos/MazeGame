#ifndef CORE_PLUGIN_HPP_
# define CORE_PLUGIN_HPP_

# include <any>
# include <string>

namespace core
{
    class Plugin
    {
        protected:
            Plugin(std::string const & type, std::any && openInputData);
            Plugin(Plugin const &) = delete;
            Plugin(Plugin &&) = delete;
            virtual ~Plugin(void);

        public:
            void *  instance(void) const;
            void    instance(void * instance);

        private:
            int load(void);

        private:
            std::string const m_type;
            void * m_instance;
            std::any m_load_arg;

        private:
            typedef void (*m_fp_unload)(Plugin *);
    };
}

#endif
