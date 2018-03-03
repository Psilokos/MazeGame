#ifndef IMAGE_HPP_
# define IMAGE_HPP_

# include <string>
# include <Magick++.h>

class Image
{
    public:
        Image(void) = default;
        Image(Image const &) = default;
        Image(Image &&) = default;
        ~Image(void) = default;

        Image & operator=(Image const &) = default;
        Image & operator=(Image &&) = default;

        void const * data(void);
        size_t cols(void) const;
        size_t rows(void) const;

        bool load(std::string const & path);

    private:
        Magick::Image m_img;
        Magick::Blob m_blob;
};

#endif
