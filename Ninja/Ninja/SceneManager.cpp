#include "SceneManager.h"
#include"Sound.h"

SceneManager * SceneManager::_instance = NULL;

SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

SceneManager * SceneManager::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new SceneManager();
	}
	return _instance;
}

void SceneManager::SetScene(Scene * x)
{
	Scene * scene_temp = _scene;
	_scene = x;
	SAFE_DELETE(scene_temp);
}

int SceneManager::getState()
{
	return _scene->getState();
}

void SceneManager::SetStateSituation(int statesituation)
{
	_scene->SetStateSituation(statesituation);
}

void SceneManager::KeyState(BYTE * state)
{
	_scene->KeyState(state);
}

void SceneManager::OnKeyDown(int KeyCode)
{
	_scene->OnKeyDown(KeyCode);
}

void SceneManager::OnKeyUp(int KeyCode)
{
	_scene->OnKeyUp(KeyCode);
}

void SceneManager::LoadResources()
{
	_scene->LoadResources();
}

void SceneManager::Update(DWORD dt)
{
	_scene->Update(dt);
}

void SceneManager::Render()
{
	_scene->Render();
}
