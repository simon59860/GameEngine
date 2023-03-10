#pragma once
#include "BaseComponent.h"
#include "glm/glm.hpp"

class RotateComponent : public BaseComponent
{
public:
	RotateComponent(GameObject* pGameObject) :BaseComponent(pGameObject) {};
	virtual ~RotateComponent() = default;

	virtual void Initialize() override;
	virtual void Update() override;

	void SetOffset(const glm::vec3& pos) { m_Offset = pos; };
	void SetRotateSpeed(float rotateSpeed) { m_RotateSpeed = rotateSpeed; };
	void SetRadius(float radius) { m_Radius = radius; };

private:
	glm::vec3 m_Offset{};
	float m_Angle{}; //radians
	float m_RotateSpeed{30}; //radians per second
	float m_Radius{30};
};

