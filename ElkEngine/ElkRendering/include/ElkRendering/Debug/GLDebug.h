#pragma once

#include <ElkTools\Debug\Assertion.h>

#define GLCall(OpenGL_Call) ElkRendering::Debug::GLDebug::GLClearError(); OpenGL_Call;

namespace ElkRendering
{
	namespace Debug
	{
		class GLDebug
		{
		public:
			static void CALLBACK DebugCallbackError(const GLenum p_source,
				const GLenum p_type,
				const GLuint p_id,
				const GLenum p_severity,
				const GLsizei p_length,
				const GLchar* p_msg,
				const void* p_data);

			static void GLClearError();
			static bool GLLogCall(const char* function, const char* file, int line);

		private:
			static std::string GetStringForSource(const GLenum p_source);
			static std::string GetStringForType(const GLenum p_type);
			static std::string GetStringForSeverity(const GLenum p_severity);
		};
	}
}