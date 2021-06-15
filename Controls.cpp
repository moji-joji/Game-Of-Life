#include"Controls.h"
Key::Key() {}

// make enum of key
Key::Key(sf::Keyboard::Key keyboardKey) {
	key = keyboardKey;
}

// // return true if a key is pressed
// bool Key::key_state() {
// 	return sf::Keyboard::isKeyPressed(key);
// }

// if the key is not alread pressed

bool Key::key_pressed() {
	if (!pressed) {
		pressed = sf::Keyboard::isKeyPressed(key);
		return sf::Keyboard::isKeyPressed(key);
	}
	else {
		pressed = sf::Keyboard::isKeyPressed(key);
		return false;
	}
}



Mouse::Mouse() {};

// store button enum
Mouse::Mouse(sf::Mouse::Button mouseButton) {
	button = mouseButton;
}


// check state
// detect mouse click
bool Mouse::sense_click() {
	if (!pressed) {
		pressed = sf::Mouse::isButtonPressed(button);
		return sf::Mouse::isButtonPressed(button);
	}
	else {
		pressed = sf::Mouse::isButtonPressed(button);
		return false;
	}
}
