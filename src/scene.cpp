#include "scene.hpp"

Scene *SceneManager::currentScene = nullptr;

void SceneManager::set_current_scene(Scene *scene){
    current_scene = scene;
    if(current_scene){
        current_scene->load_resources();
    }
}

void SceneManager::run(){
    Clock clock;
    clock.tick();

    if(current_scene != nullptr){
        current_scene->update(clock.delta / 1000.0f);
        current_scene->render();
        current_scene->play_audio();
    }
}

void SceneManager::load_scene(Scene *scene){
    if(current_scene != nullptr){
        current_scene->unload_resources();
    }

    current_scene = scene;
    if(current_scene != nullptr){
        current_scene->load_resources();
    }
}

void SceneManager::unload_scene(){
    if(current_scene != nullptr){
        current_scene->unload_resources();
        current_scene = nullptr;
    }
}

void SceneManager::destroy_scene(Scene *scene){
    if(scene){
        scene->unload_resources();
        delete scene;
    }
}