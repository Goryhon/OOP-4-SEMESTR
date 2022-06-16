#include <iostream>
#include <string>
#include <vector>
#include <regex>

std::vector<std::pair<std::string, std::string>> ru_eng_replace = {
        {"а", "a"},
        {"б", "b"},
        {"в", "v"},
        {"г", "g"},
        {"д", "d"},
        {"е", "e"},
        {"ё", "yo"},
        {"ж", "zh"},
        {"з", "z"},
        {"и", "i"},
        {"й", "i"},
        {"к", "k"},
        {"л", "l"},
        {"м", "m"},
        {"н", "n"},
        {"о", "o"},
        {"п", "p"},
        {"р", "r"},
        {"с", "s"},
        {"т", "t"},
        {"у", "u"},
        {"ф", "f"},
        {"х", "h"},
        {"ц", "c"},
        {"ч", "ch"},
        {"ш", "sh"},
        {"щ", "sh'"},
        {"ь", "'"},
        {"ы", "i"},
        {"ъ", ""},
        {"э", "e"},
        {"ю", "yu"},
        {"я", "ya"}
};

class SpeakerInterface {
public:
    virtual std::string getSpeech() = 0;
};

class RussianSpeaker : public SpeakerInterface {
private:
    std::string speech;

public:
    RussianSpeaker(const std::string &speech) {
        this->speech = speech;
    }

    std::string getSpeech() override {
        return this->speech;
    }
};

class EnglishSpeaker : public SpeakerInterface {
private:
    std::string speech;

public:
    EnglishSpeaker(const std::string &speech) {
        this->speech = speech;
    }

    std::string getSpeech() override {
        return this->speech;
    }
};

// Адаптер. Переводит русские символы в транслит
class RussianToEnglishAdapter : public SpeakerInterface {
private:
    RussianSpeaker *adaptee;

public:
    RussianToEnglishAdapter(RussianSpeaker *ru_speaker) {
        this->adaptee = ru_speaker;
    }

    std::string getSpeech() override {
        std::string ru_str = this->adaptee->getSpeech();
        std::string en_str = ru_str;
        for (auto & i : ru_eng_replace) {
            en_str = std::regex_replace(  // Заменяем русские буквы на транслит
                    en_str,
                    std::regex(i.first),
                    i.second);
        }
        return en_str;
    }
};

void printEnglishSpeech(SpeakerInterface* speaker) {
    std::cout << speaker->getSpeech() << std::endl;
}

int main() {
    auto ru_speaker = new RussianSpeaker("русские есть? ау, где русские?");
    auto ru_speaker_adapted = new RussianToEnglishAdapter(ru_speaker);
    auto en_speaker = new EnglishSpeaker("Any Englishmen?");

    printEnglishSpeech(en_speaker);
    printEnglishSpeech(ru_speaker_adapted);
}