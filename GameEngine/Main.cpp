#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "GameEngine.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextRenderComponent.h"
#include "Scene.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "FPSCounter.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto go = std::make_unique<dae::GameObject>();
	auto renderComponent = std::make_unique<dae::RenderComponent>(go.get());
	renderComponent->SetTexture("background.tga");
	go->AddComponent<dae::RenderComponent>(std::move(renderComponent));
	scene.Add(std::move(go));

	go = std::make_unique<dae::GameObject>();
	renderComponent = std::make_unique<dae::RenderComponent>(go.get());
	renderComponent->SetTexture("logo.tga");
	go->AddComponent<dae::RenderComponent>(std::move(renderComponent));
	go->SetPosition(216, 180);
	scene.Add(std::move(go));

	go = std::make_unique<dae::GameObject>();
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto textRenderComponent = std::make_unique<dae::TextRenderComponent>(go.get(), "Programming 4 Assignment", font);
	go->AddComponent<dae::TextRenderComponent>(std::move(textRenderComponent));
	go->SetPosition(80, 20);
	scene.Add(std::move(go));

	//fps counter gameobject
	go = std::make_unique<dae::GameObject>();
	font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	textRenderComponent = std::make_unique<dae::TextRenderComponent>(go.get(), "fps test", font);
	go->AddComponent<dae::TextRenderComponent>(std::move(textRenderComponent));
	auto fpsCounter = std::make_unique<dae::FPSCounter>(go.get());
	go->AddComponent<dae::FPSCounter>(std::move(fpsCounter));
	go->SetPosition(80, 120);
	scene.Add(std::move(go));
}

int main(int, char*[]) {
	dae::GameEngine engine("../Data/");
	engine.Run(load);
    return 0;
}