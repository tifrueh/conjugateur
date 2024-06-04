// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <map>
#include <string>
#include <vector>
#include <random>

#include "verb.db.hpp"


// This namespace contains all functionality related to manipulating the verb database.
namespace cjgt {

    struct Category {
        unsigned int id;
        std::wstring name;
        std::vector<const verbDB::Verb*> verbs;

        bool operator==(const Category& Category) const;
    };

    struct Tense {
        std::vector<const verbDB::Verb*>::size_type position;
        std::wstring name;
        std::vector<std::wstring> persons;

        bool operator==(const Tense& Tense) const;
    };

    struct QuizData {
        const std::wstring* verb_name;
        const Tense* tense;
        const std::wstring* person;
        const std::wstring* form;

        bool operator==(const QuizData& QuizItemData) const;
    };

    class Language{
        public:
            Language(
                    const std::wstring& name,
                    const std::vector<Category>& categories,
                    const std::vector<Tense>& tenses
            );

            const std::wstring* getName() const;
            std::vector<const Category*> getCategories() const;
            std::vector<const Tense*> getTenses() const;
            std::map<std::wstring, const verbDB::Verb*> getVerbs() const;
            const verbDB::Verb* getVerb(std::wstring) const;

            QuizData getRandomQuizData(const std::vector<const Category*>& categories, const std::vector<const Tense*>& tenses) const;

        private:
            std::wstring name;
            std::vector<Category> categories;
            std::vector<Tense> tenses;
            std::map<std::wstring, const verbDB::Verb*> verbs;
    };

    const std::wstring* getVerbForm(
            const verbDB::Verb* verb,
            const std::vector<std::wstring>::size_type& person,
            const Tense* tense
    );

    std::wstring strip(const std::wstring& string);

    extern const Language french;
}
