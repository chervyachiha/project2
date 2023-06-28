#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
namespace mt {
    Game::Game() {}
    Game::~Game() {
        if (m_window != nullptr)
            delete m_window;
    }

    void Game::Setup()
    {
        m_window = new sf::RenderWindow(sf::VideoMode(200,200), "SFML works!");
    }
}