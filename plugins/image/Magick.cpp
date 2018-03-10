#include "Magick.hpp"

void const *
Magick::data(void)
{
    return m_blob.data();
}

size_t
Magick::cols(void) const
{
    return m_img.columns();
}

size_t
Magick::rows(void) const
{
    return m_img.rows();
}

bool
Magick::load(std::string const & path)
{
    m_img.ping(path);
    if (!m_img.isValid())
        return false;

    m_img.read(path);
    m_img.write(&m_blob, "RGBA");

    return true;
}
