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

        bool operator==(const Category& Category) const;
    };

    struct Tense {
        std::vector<verbDB::Verb*>::size_type position;
        std::wstring name;
        std::vector<std::wstring> persons;

        bool operator==(const Tense& Tense) const;
    };

    struct QuizItem {
        std::wstring* verb_name;
        Tense* tense;
        std::wstring* person;
        std::wstring* form;

        bool operator==(const QuizItem& QuizItem) const;
    };

    class Language{
        public:
            Language(
                    const std::wstring& name,
                    const std::vector<Category>& categories,
                    const std::vector<Tense>& tenses
            );

            void addVerb(verbDB::Verb*, Category*);

            std::wstring* getName();
            std::vector<Category>* getCategories();
            std::vector<Tense>* getTenses();
            std::map<std::wstring, verbDB::Verb*>* getVerbs();

            QuizItem getRandomQuizItem(const std::vector<Category*>& categories, const std::vector<Tense*>& tenses);

        private:
            std::wstring name;
            std::vector<Category> categories;
            std::vector<Tense> tenses;
            std::map<std::wstring, verbDB::Verb*> verbs;
            std::map<Category*, std::vector<verbDB::Verb*>> categorised_verbs;
            std::random_device random_device;
            std::default_random_engine random_engine;

            std::wstring* getVerbForm(
                    verbDB::Verb* verb,
                    const std::vector<std::wstring>::size_type& person,
                    Tense* tense
            );
    };

    extern Language french;
}
