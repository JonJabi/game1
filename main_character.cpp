#include <godot/godot.hpp>
#include <godot/classes/node2d.hpp>
#include <godot/classes/input.hpp>
#include <godot/classes/character_body2d.hpp>
#include <godot/core/class_db.hpp>

using namespace godot;
using namespace jenova::sdk;




JENOVA_SCRIPT_BEGIN
JENOVA_PROPERTY(int, speed, 100);
JENOVA_PROPERTY(int, jump_hight, -200);



void OnPhysicsProcess(Caller* instance, Variant& _delta)
{
	CharacterBody2D* self = GetSelf<CharacterBody2D>(instance);
	Input* input = Input::get_singleton();
	Vector2 vel{ self->get_velocity() };

	if (!self->is_on_floor()) {
		vel.y += +jump_hight;
	}
		
	else {
		if (self->is_on_floor()) {
			if (input->is_action_pressed("RIGHT")) {
				vel.x = speed;
			}
			else if (input->is_action_pressed("LEFT")) {
				vel.x = -speed;
			}
			else {
				vel.x = 0;
			}

			if (input->is_action_pressed("JUMP")) {
				vel.y = -speed;
			}
			else if (input->is_action_pressed("DOWN")) {
				vel.y = speed;
			}
			else {
				vel.y = 0;
			}
	}

	
	}



	self->set_velocity(vel);
	self->move_and_slide();
}


JENOVA_SCRIPT_END
