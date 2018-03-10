#ifndef MAGICK_HPP_
# define MAGICK_HPP_

# include <string>
# include <Magick++.h>

class Magick
{
    public:
        Magick(void) = default;
        Magick(Magick const &) = default;
        Magick(Magick &&) = default;
        ~Magick(void) = default;

        Magick & operator=(Magick const &) = default;
        Magick & operator=(Magick &&) = default;

        void const * data(void);
        size_t cols(void) const;
        size_t rows(void) const;

        bool load(std::string const & path);

    private:
        Magick::Image m_img;
        Magick::Blob m_blob;
};

#endif
