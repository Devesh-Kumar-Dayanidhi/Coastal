#shader vertex 
#version 330 core 
 
layout(location = 0) in vec4 position; 
uniform vec2 u_Transform;
 
void main() 
{ 
    gl_Position = vec4(position.xy + u_Transform.xy, position.z, position.w);
} 
 
#shader fragment 
#version 330 core
 
out vec4 color; 
uniform vec4 u_Color; 
 
void main() 
{ 
    color = u_Color; 
}