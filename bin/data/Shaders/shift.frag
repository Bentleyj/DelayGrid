#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

uniform sampler2DRect source;
uniform vec2 cellSize;
uniform vec2 bufferSize;

void main()
{
    vec2 pos = gl_FragCoord.xy;
    vec4 color = vec4(0.0, 0.0, 0.0, 1.0);
	
    if(pos.x - cellSize.x < 0) {
		pos.x += cellSize.x * (int(bufferSize.x / cellSize.x) - 1);
		pos.y -= cellSize.y;
    } else {
    	pos.x -= cellSize.x;
    }
	color = vec4(pos.y / bufferSize.y, 0.0, 0.0, 1.0);
	color = texture2DRect(source, pos);



    gl_FragColor = color;
}