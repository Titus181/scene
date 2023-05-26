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

		Scene scene1("�A�Ө�@�ӯ������˪L�A�A�n��ܦV���٬O�V�k�H", { "�V��","�V�k" }, { 1,2 });
		Scene scene2("�A���i�F�@�Ӷ·t���}�ޡA�A�n�I�G����ܡH", { "�O","�_" }, { 3,4 });
		Scene scene3("�A�ݨ��@�����j���Ǫ�!�A�n�԰��٬O�k�]�H", { "�԰�","�k�]" }, { 5,6 });
		Scene scene4("�A�~��e�i�A���S������S�O���o�{�C", { "�~��" }, { 7 });
		Scene scene5("�A���ѤF�Ǫ�!�AĹ�o�F�C��!", {}, {});
		Scene scene6("�A���հk�]�A���Ǫ��l�W�F�A�A�A��F!", {}, {});
		Scene scene7("�A����F�˪L�����Y�A�AĹ�F!", {}, {});

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
			std::cout << "�п�ܡG";
			std::cin >> choice;

			currentScene = current.getNextScene(choice);
			if (currentScene == -1) {
				std::cout << "�L�Ŀ��!�Э��s��ܡC" << std::endl;
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