/*
 * ObjectivelyMVC: MVC framework for OpenGL and SDL2 in c.
 * Copyright (C) 2014 Jay Dolan <jay@jaydolan.com>
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 */

#ifndef _ObjectivelyMVC_Control_h_
#define _ObjectivelyMVC_Control_h_

#include <Objectively/MutableArray.h>

#include <ObjectivelyMVC/Action.h>
#include <ObjectivelyMVC/View.h>

/**
 * @file
 * 
 * @brief Controls are Views which can respond to events.
 */

typedef struct Control Control;
typedef struct ControlInterface ControlInterface;

/**
 * @brief Control states, which are bit-masked.
 */
typedef enum {
	ControlStateDefault = 0x0,
	ControlStateHighlighted	= 0x1,
	ControlStateDisabled = 0x2,
	ControlStateSelected = 0x4,
	ControlStateFocused	= 0x8,
} ControlState;

/**
 * @brief The Control type.
 */
struct Control {

	/**
	 * @brief The parent.
	 *
	 * @private
	 */
	View view;

	/**
	 * @brief The typed interface.
	 *
	 * @private
	 */
	ControlInterface *interface;
	
	/**
	 * @brief The Actions bound to this Control.
	 *
	 * @private
	 */
	MutableArray *actions;

	/**
	 * @brief The bit mask of ControlState.
	 */
	int state;
};

/**
 * @brief The Control interface.
 */
struct ControlInterface {

	/**
	 * @brief The parent interface.
	 */
	ViewInterface viewInterface;
	
	/**
	 * @fn Action *Control::actionForEvent(const Control 8self, const SDL_Event *event)
	 *
	 * @memberof Control
	 */
	Action *(*actionForEvent)(const Control *self, const SDL_Event *event);
	
	/**
	 * @fn void Control::addActionForEventType(Control *self, SDL_EventType eventType, ActionFunction function, ident data)
	 *
	 * @brief Adds an Action for the given event type to this Control.
	 
	 * @param eventType The event type.
	 * @param function The ActionFunction.
	 * @param data The data.
	 *
	 * @memberof Control
	 */
	void (*addActionForEventType)(Control *self, SDL_EventType eventType, ActionFunction function, ident data);
	
	/**
	 * @fn _Bool Control::enabled(const Control *self)
	 *
	 * @return True if this Control is enabled, false otherwise.
	 *
	 * @memberof Control
	 */
	_Bool (*enabled)(const Control *self);
	
	/**
	 * @fn _Bool Control::focused(const Control *self)
	 *
	 * @return True if this Control is focused, false otherwise.
	 *
	 * @memberof Control
	 */
	_Bool (*focused)(const Control *self);
	
	/**
	 * @fn _Bool Control::highlighted(const Control *self)
	 *
	 * @return True if this Control is highlighted, false otherwise.
	 *
	 * @memberof Control
	 */
	_Bool (*highlighted)(const Control *self);
	
	/**
	 * @fn Control Control::initWithFrame(Control *self, const SDL_Rect *frame)
	 *
	 * @brief Initializes this Control with the specified frame.
	 *
	 * @param frame The frame.
	 *
	 * @return The intialized Control, or `NULL` on error.
	 *
	 * @memberof Control
	 */
	Control *(*initWithFrame)(Control *self, const SDL_Rect *frame);
	
	/**
	 * @fn _Bool Control::selected(const Control *self)
	 *
	 * @return True if this Control is selected, false otherwise.
	 *
	 * @memberof Control
	 */
	_Bool (*selected)(const Control *self);
};

/**
 * @brief The Control Class.
 */
extern Class _Control;

#endif