#include <iostream>
#include <string>
#include <vector>


class Scene {
private:
	std::string description;
	std::vector<std::string> choices;
	std::vector<int> nextScenes;

public:
	Scene(const std::string& desc, const std::vector<std::string>& ch, const std::vector<int>& next) {
		this->description = desc;
		this->choices = ch;
		this->nextScenes = next;
	}

	void display() {
		std::cout << description << std::endl;
		for (int i = 0; i < choices.size(), ++i) {
			std::cout << i + 1 << ". " << choices[i] << std::endl;
		}
	}

	int getNextScenes(int choice) {
		if (choice >= 1 && choice <= nextScenes.size()) {
			return nextScenes[choice - 1];
		}
		else {
			return -1;0
		}
	}
};


int main() {






	system("PAUSE");
	return 0;
}