#include "GLFunction.hpp"
#include "Texture.hpp"

Texture::Texture(void)
{
    glCall(glGenTextures, 1, &m_id);
}

Texture::~Texture(void)
{
    glCall(glDeleteTextures, 1, &m_id);
}

bool
Texture::load(std::string const & path)
{
    if (!m_img.load(path))
        return false;

    glCall(glBindTexture, GL_TEXTURE_2D, m_id);
    glCall(glTexImage2D, GL_TEXTURE_2D, 0, GL_RGBA8, m_img.columns(), m_img.rows(), 0, GL_RGBA, GL_UNSIGNED_BYTE, m_img.data());
    glCall(glTexParameteri, GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glCall(glTexParameteri, GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glCall(glGenerateMipmap, GL_TEXTURE_2D);

    return true;
}

void
Texture::use(unsigned int uniformLocation) const
{
    glCall(glActiveTexture, GL_TEXTURE0 + m_id - 1);
    glCall(glBindTexture, GL_TEXTURE_2D, m_id);
    glCall(glUniform1i, uniformLocation, GL_TEXTURE0 + m_id - 1);
}
