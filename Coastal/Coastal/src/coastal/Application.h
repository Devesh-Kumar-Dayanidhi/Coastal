#pragma once

#include "Drawing.h"
#include "Scene.h"
#include "Renderer.h"

#include "OpenGLObjectManager.h"

namespace Coastal {

	typedef unsigned int uint32_t;

	class Application
	{
	public:
		Application() = default;
	public:
		inline uint32_t GetWindowWidth() const { return m_ViewportWidth; }
		inline uint32_t GetWindowHeight() const { return m_ViewportHeight; }
		inline const Coastal::Rgba& GetWindowColor() const { return m_ClearColor; }
		inline const std::string& GetWindowTitle() const { return m_Title; }
		inline const Coastal::Renderer& GetCoastalRenderer() const { return m_CoastalRenderer; }
		inline const Coastal::OpenGLObjectManager& GetCoastalManager() const { return m_CoastalManager; }
	protected:
		virtual void Start() = 0;
		virtual void OnUpdate() = 0;
	protected:
		Scene m_Scene;
		Renderer m_CoastalRenderer;
		OpenGLObjectManager m_CoastalManager;
	private:
		uint32_t m_ViewportWidth = 400, m_ViewportHeight = 400;
		Coastal::Rgba m_ClearColor = Coastal::Rgba(0.1f, 0.7f, 0.6f, 1.0f);
		std::string m_Title = "Coastal Application";
	};

}