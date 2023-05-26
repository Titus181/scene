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
		for (int i = 0; i < choices.size(); ++i) {
			std::cout << i + 1 << ". " << choices[i] << std::endl;
		}
	}

	int getNextScene(int choice) {
		if (choice >= 1 && choice <= nextScenes.size()) {
			return nextScenes[choice - 1];
		}
		else {
			return -1;
		}
	}
};

class Game {
private:
	std::vector<Scene> scenes;
	int currentScene;

public:
	Game() {
		this->currentScene = 0;

		Scene scene1("你來到一個神祕的森林，你要選擇向左還是向右？", { "向左","向右" }, { 1,2 });
		Scene scene2("你走進了一個黑暗的洞穴，你要點亮火把嗎？", { "是","否" }, { 3,4 });
		Scene scene3("你看見一隻巨大的怪物!你要戰鬥還是逃跑？", { "戰鬥","逃跑" }, { 5,6 });
		Scene scene4("你繼續前進，但沒有任何特別的發現。", { "繼續" }, { 7 });
		Scene scene5("你打敗了怪物!你贏得了遊戲!", {}, {});
		Scene scene6("你嘗試逃跑，但怪物追上了你，你輸了!", {}, {});
		Scene scene7("你走到了森林的盡頭，你贏了!", {}, {});

		scenes.push_back(scene1);
		scenes.push_back(scene2);
		scenes.push_back(scene3);
		scenes.push_back(scene4);
		scenes.push_back(scene5);
		scenes.push_back(scene6);
		scenes.push_back(scene7);
	}

	void play() {
		while (currentScene != -1) {
			Scene& current = scenes[currentScene];
			current.display();

			int choice;
			std::cout << "請選擇：";
			std::cin >> choice;

			currentScene = current.getNextScene(choice);
			if (currentScene == -1) {
				std::cout << "無效選擇!請重新選擇。" << std::endl;
			}
			std::cout << std::endl;
		}
	}
};

int main() {


	Game game;
	game.play();



	system("PAUSE");
	return 0;
}