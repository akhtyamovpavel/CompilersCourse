#pragma once

#include <cstdio>
#include <unordered_map>

enum Token {
	TOKEN_HELP = 1,
	TOKEN_UP,
	TOKEN_DOWN,
	TOKEN_LEFT,
	TOKEN_RIGHT,
	TOKEN_EXIT,
	TOKEN_ERROR,
};


static std::unordered_map<Token, std::string> TOKEN_MAP = {
    {TOKEN_HELP, "Help - [h|help]"},
    {TOKEN_UP, "Up - [u|up]"},
    {TOKEN_DOWN, "Down - [d|down]"},
    {TOKEN_LEFT, "Left - [l|left]"},
    {TOKEN_RIGHT, "Right - [r|right]"},
    {TOKEN_ERROR, "Exit - [e|exit]"}
};
