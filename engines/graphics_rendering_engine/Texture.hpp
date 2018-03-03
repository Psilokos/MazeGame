#ifndef TEXTURE_HPP_
# define TEXTURE_HPP_

# include <string>
# include <GL/glew.h>
# include <Image.hpp>

class Texture
{
    public:
        Texture(void);
        Texture(Texture const &) = default;
        Texture(Texture &&) = default;
        ~Texture(void);

        Texture & operator=(Texture const &) = default;
        Texture & operator=(Texture &&) = default;

        bool load(std::string const & path);
        void use(unsigned int uniformLocation) const;

    private:
        GLuint m_id;
        Image m_img;
};

#endif
