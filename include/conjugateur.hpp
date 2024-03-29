// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in ../src/main.cpp

#pragma once

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

#include "verb.db.hpp"


// This namespace contains all functionality related to verb forms.
namespace cjgt {

    // A structure containing a form of a verb, including its corresponding
    // infinitif, tense and person.
    struct VerbForm {
        std::wstring infinitif;
        std::wstring tense;
        std::wstring person;
        std::wstring form;
        
        // Compare two verb forms to decide if they are equal.
        // They are considered equal if the infinitive, the person, the form and the tense are equal.
        bool operator==(const VerbForm& verbForm) const;
    };
    
    // A structure containing all possible variations of a verb form.
    struct QuizData {
        std::wstring infinitif;
        std::wstring translation;
        std::wstring tense;
        std::wstring person;
        std::vector<std::wstring> forms;
        
        // Compare two QuizDatas to decide if they are equal.
        // They are considered equal if the infinitive and the person are equal.
        bool operator==(const QuizData& verbForm) const;
    };

    // Search a verb based on its label: returns a pointer to the verb.
    const verbDB::Verb* getVerb(const std::wstring& label);
    
    // Retrieve a verb form based on the verb, the tense and the person.
    VerbForm getVerbForm(const verbDB::Verb& verb, const verbDB::Tense& tense, const verbDB::Person& person);
    
    // Retrieve a verb form based on the verb, the tense (as int) and the person (as int).
    VerbForm getVerbForm(const verbDB::Verb& verb, const int& tense, const int& person);
    
    // Retrieve all verb form variations based on the verb, the tense and the person.
    QuizData getQuizData(const verbDB::Verb& verb, const verbDB::Tense& tense, const verbDB::Person& person);
    
    // Retrieve all verb form variations based on the verb, the tense (as int) and the person (as int).
    QuizData getQuizData(const verbDB::Verb& verb, const int& tense, const int& person);

    // Return a tense (provided as enum) as string.
    std::wstring getTense(const verbDB::Tense& tense);

    // Return a tense (provided as int) as string.
    std::wstring getTense(const int& tense);

    // Return a person (provided as enum) as string.
    std::wstring getPerson(const verbDB::Person& person);

    // Return a person (provided as int) as string.
    std::wstring getPerson(const int& person);

    // Return verb form as string.
    // Je is concatenated automatically, e. g. "j'ai fait".
    std::wstring getFormString(const VerbForm& verbForm);

    // Strip a string of leading and trailing whitespaces.
    std::wstring strip(const std::wstring& string);
}
