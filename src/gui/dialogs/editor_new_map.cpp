/* $Id$ */
/*
   copyright (C) 2008 by mark de wever <koraq@xs4all.nl>
   part of the battle for wesnoth project http://www.wesnoth.org/

   this program is free software; you can redistribute it and/or modify
   it under the terms of the gnu general public license version 2
   or at your option any later version.
   this program is distributed in the hope that it will be useful,
   but without any warranty.

   see the copying file for more details.
*/

#include "gui/dialogs/editor_new_map.hpp"

#include "foreach.hpp"
#include "gui/dialogs/field.hpp"
#include "gui/widgets/button.hpp"
#include "gui/widgets/listbox.hpp"
#include "gui/widgets/settings.hpp"
#include "gui/widgets/text_box.hpp"
#include "gui/widgets/window.hpp"
#include "gui/widgets/window_builder.hpp"
#include "language.hpp"
#include "log.hpp"
#include "preferences.hpp"
#include "video.hpp"
#include "wml_exception.hpp"

#define DBG_GUI LOG_STREAM_INDENT(debug, widget)
#define LOG_GUI LOG_STREAM_INDENT(info, widget)
#define WRN_GUI LOG_STREAM_INDENT(warn, widget)
#define ERR_GUI LOG_STREAM_INDENT(err, widget)

namespace gui2 {

teditor_new_map::teditor_new_map() :
	map_width_(register_text("width", false)),
	map_height_(register_text("height", false))
{
}

void teditor_new_map::set_map_width(int value) 
{ 
	map_width_->set_value(lexical_cast<std::string>(value));
}

int teditor_new_map::map_width() const
{
	return lexical_cast_default<int>(map_width_->get_value());
}

void teditor_new_map::set_map_height(int value)
{ 
	map_height_->set_value(lexical_cast<std::string>(value));
}

int teditor_new_map::map_height() const
{
	return lexical_cast_default<int>(map_height_->get_value());
}

twindow teditor_new_map::build_window(CVideo& video)
{
	return build(video, get_id(EDITOR_NEW_MAP));
}

} // namespace gui2
