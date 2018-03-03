#include <Image.hpp>

void const *
Image::data(void)
{
    return m_blob.data();
}

size_t
Image::cols(void) const
{
    return m_img.columns();
}

size_t
Image::rows(void) const
{
    return m_img.rows();
}

bool
Image::load(std::string const & path)
{
    m_img.ping(path);
    if (!m_img.isValid())
        return false;

    m_img.read(path);
    m_img.write(&m_blob, "RGBA");

    return true;
}
