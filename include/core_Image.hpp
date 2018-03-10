#ifndef CORE_IMAGE_HPP_
# define CORE_IMAGE_HPP_

# include <core_Plugin.hpp>

namespace core
{
    class Image : public Plugin
    {
        public:
            Image(std::string const & path = "");
            Image(Image const &) = delete;
            Image(Image &&) = delete;
            virtual ~Image(void) = default;

            std::string const & path(void) const;
            void                path(std::string const & path);

            void *              data(void) const;

            bool isLoaded(void) const;

        private:
            typedef void *(*)(Image const *) fp_get_data;
            // typedef std::string const & (*)(void) fp_get_path <= can this compile, not crash (auto deref)
            typedef bool (*)(Image const *) fp_is_loaded;

            fp_get_data m_fp_get_data;
            fp_is_loaded m_fp_is_loaded;
    };
}

#endif
