#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace mt
{
    class Game
    {
    private:
        int m_width, m_height;
        std::string m_caption;
        sf::RenderWindow* m_window = nullptr;

    public:
        Game();
        ~Game();
        void Setup();
    };
}