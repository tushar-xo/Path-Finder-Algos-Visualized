#include <array>
#include <chrono>
#include <queue>
#include <bits/stdc++.h>
#include <map>
#include <SFML/Graphics.hpp>
#include <cmath> // Include cmath for floor

#include "Headers/DrawText.hpp"
#include "Headers/Global.hpp"
#include "Headers/DrawMap.hpp"
#include "Headers/GetMouseCell.hpp"
#include "Headers/Astar.hpp"
#include "Headers/BFS.hpp"
#include "Headers/Dijkstra.hpp"

// Main function
int main()
{
    // BFS variables
    bool bfs_finished = false;
    unsigned short bfs_path_length = 0;
    unsigned short bfs_total_checks = 0;
    std::chrono::microseconds bfs_duration(0);
    std::map<gbl::Position<>, gbl::Position<>> bfs_previous_cell;
    std::queue<gbl::Position<>> bfs_path_queue;
    gbl::Map<> bfs_map = {};

    // Dijkstra's variables
    bool dijkstra_finished = false;
    unsigned short dijkstra_path_length = 0;
    unsigned short dijkstra_total_checks = 0;
    std::chrono::microseconds dijkstra_duration(0);
    std::map<gbl::Position<>, gbl::Position<>> dijkstra_previous_cell;
    gbl::Map<float> dijkstra_distances = {};
    std::priority_queue<gbl::Position<>, std::vector<gbl::Position<>>, DijkstraComparison> dijkstra_path_queue;
    gbl::Map<> dijkstra_map = {};

    // A* variables
    bool astar_finished = false;
    unsigned short astar_path_length = 0;
    unsigned short astar_total_checks = 0;
    std::chrono::microseconds astar_duration(0);
    std::map<gbl::Position<>, gbl::Position<>> astar_previous_cell;
    std::vector<gbl::Position<>> astar_path_vector;
    gbl::Map<> astar_map = {};
    gbl::Map<float> astar_f_scores = {};
    gbl::Map<float> astar_g_scores = {};
    gbl::Map<float> astar_h_scores = {};

    bool mouse_pressed = false;
    bool pause_search = true;
    std::chrono::microseconds lag(0);
    std::chrono::steady_clock::time_point previous_time;
    sf::Event event;

    sf::RenderWindow window(sf::VideoMode(gbl::SCREEN::RESIZE * gbl::SCREEN::WIDTH, gbl::SCREEN::RESIZE * gbl::SCREEN::HEIGHT), "Pathfinding", sf::Style::Close);
    window.setView(sf::View(sf::FloatRect(0, 0, gbl::SCREEN::WIDTH, gbl::SCREEN::HEIGHT)));

    sf::Sprite map_sprite;
    sf::Texture font_texture, map_texture;

    // Load textures
    font_texture.loadFromFile("Resources/Images/Font.png");
    map_texture.loadFromFile("Resources/Images/Map.png");
    
    gbl::Map<> map = {};
    gbl::Position<> finish_position(gbl::MAP::COLUMNS - 1, gbl::MAP::ROWS - 1);
    gbl::Position<> start_position(0, 0);

    // Initialize map
    for (auto& column : map) {
        column.fill(gbl::MAP::Cell::Empty);
    }

    bfs_map = map;
    dijkstra_map = map;
    astar_map = map;

    map_sprite.setTexture(map_texture);
    previous_time = std::chrono::steady_clock::now();

    while (window.isOpen()) {
        std::chrono::microseconds delta_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previous_time);
        lag += delta_time;
        previous_time += delta_time;

        while (gbl::SCREEN::FRAME_DURATION <= lag) {
            bool map_updated = false;
            lag -= gbl::SCREEN::FRAME_DURATION;

            while (window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::KeyPressed:
                        switch (event.key.code) {
                            case sf::Keyboard::Enter: // Pause/Resume search
                                pause_search = !pause_search;
                                break;
                            case sf::Keyboard::R: // Restart search
                                map_updated = true;
                                break;
                            case sf::Keyboard::Space: // Clear map
                                for (unsigned short a = 0; a < gbl::MAP::COLUMNS; ++a) {
                                    for (unsigned short b = 0; b < gbl::MAP::ROWS; ++b) {
                                        map[a][b] = gbl::MAP::Cell::Empty;
                                    }
                                }
                                map_updated = true;
                                break;
                        }
                        break;
                }
            }

            // Mouse input handling...
            // Resetting maps and running algorithms...
            // Drawing everything...
        }
    }
}
