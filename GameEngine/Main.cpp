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
#include "MoveComponent.h"
#include "RotateComponent.h"
#include "DestroyComponent.h"

void load()
{
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	//background
	auto pGameObject = scene.CreateAndAddGameObject();
	auto renderComponent = pGameObject->CreateAndAddComponent<RenderComponent>();
	renderComponent->SetTexture("background.tga");

	//logo
	pGameObject = scene.CreateAndAddGameObject();
	renderComponent = pGameObject->CreateAndAddComponent<RenderComponent>();
	renderComponent->SetTexture("logo.tga");
	pGameObject->GetTransform()->SetLocalPosition(216, 180, 0);

	//title
	pGameObject = scene.CreateAndAddGameObject();
	auto textRenderComponent = pGameObject->CreateAndAddComponent<TextRenderComponent>();
	textRenderComponent->SetText("Programming 4 Assignment");
	textRenderComponent->SetFont(ResourceManager::GetInstance().LoadFont("Lingua.otf", 36));
	
	pGameObject->GetTransform()->SetLocalPosition(80, 20, 0);

	//fps counter gameobject
	pGameObject = scene.CreateAndAddGameObject();
	textRenderComponent = pGameObject->CreateAndAddComponent<TextRenderComponent>();
	textRenderComponent->SetText("fps test");
	textRenderComponent->SetFont(ResourceManager::GetInstance().LoadFont("Lingua.otf", 12));
	pGameObject->CreateAndAddComponent<FPSCounter>();
	pGameObject->GetTransform()->SetLocalPosition(20, 20, 0);

	//chef gameobject
	auto pChef = scene.CreateAndAddGameObject();
	renderComponent = pChef->CreateAndAddComponent<RenderComponent>();
	renderComponent->SetTexture("chef.png");
	auto rotateComponent = pChef->CreateAndAddComponent<RotateComponent>();
	rotateComponent->SetOffset({ 250,250,0 });
	rotateComponent->SetRadius(50);
	rotateComponent->SetRotateSpeed(3);
	
	//bean gameobject
	auto pBean = scene.CreateAndAddGameObject();
	renderComponent = pBean->CreateAndAddComponent<RenderComponent>();
	renderComponent->SetTexture("bean.png");
	rotateComponent = pBean->CreateAndAddComponent<RotateComponent>();
	rotateComponent->SetOffset({ 0,0,0 });
	rotateComponent->SetRadius(30);
	rotateComponent->SetRotateSpeed(-3);
	auto destroyComponent = pBean->CreateAndAddComponent<DestroyComponent>();
	destroyComponent->SetLifeTime(2);
	pBean->SetParent(pChef, false);
}

int main(int, char*[]) {
	GameEngine engine("../Data/");
	engine.Run(load);
    return 0;
}