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

#pragma once

#include <ObjectivelyMVC/View.h>

/**
 * @file
 *
 * @brief The CollectionItemView type.
 */

typedef struct CollectionItemView CollectionItemView;
typedef struct CollectionItemViewInterface CollectionItemViewInterface;

/**
 * @brief The CollectionItemView type.
 *
 * @extends View
 *
 * @ingroup
 */
struct CollectionItemView {
	
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
	CollectionItemViewInterface *interface;

	/**
	 * @brief The object this item represents.
	 */
	ident object;
};

/**
 * @brief The CollectionItemView interface.
 */
struct CollectionItemViewInterface {
	
	/**
	 * @brief The parent interface.
	 */
	ViewInterface viewInterface;
	
	/**
	 * @fn CollectionItemView *CollectionItemView::initWithFrame(CollectionItemView *self, const SDL_Rect *frame)
	 *
	 * @brief Initializes this CollectionItemView with the specified frame.
	 *
	 * @param frame The frame.
	 *
	 * @return The initialized CollectionItemView, or `NULL` on error.
	 *
	 * @memberof CollectionItemView
	 */
	CollectionItemView *(*initWithFrame)(CollectionItemView *self, const SDL_Rect *frame);
	
	// ..
};

/**
 * @brief The CollectionItemView Class.
 */
extern Class _CollectionItemView;
