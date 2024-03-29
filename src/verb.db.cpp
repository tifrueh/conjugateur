// Copyright (C) 2023-2024 Timo Früh
// The full copyright notice can be found in main.cpp

#include "verb.db.hpp"


const std::array<std::wstring, 9> verbDB::tenseStrings {
    L"infinitif",
    L"participe présent",
    L"présent",
    L"imparfait",
    L"futur",
    L"passé composé",
    L"plus-que-parfait",
    L"subjonctif",
    L"conditionnel"
};

const std::array<std::wstring, 9> verbDB::personStrings {
    L"",
    L"je/j'",
    L"tu",
    L"il",
    L"elle",
    L"nous",
    L"vous",
    L"ils",
    L"elles"
};

const std::vector<const verbDB::Verb*> verbDB::allVerbs {
    &verbDB::acheter,
    &verbDB::agir,
    &verbDB::aimer,
    &verbDB::aller,
    &verbDB::amener,
    &verbDB::apercevoir,
    &verbDB::apparaitre,
    &verbDB::appeler,
    &verbDB::applaudir,
    &verbDB::appuyer,
    &verbDB::atteindre,
    &verbDB::attendre,
    &verbDB::avancer,
    &verbDB::avoir,
    &verbDB::battre,
    &verbDB::bavarder,
    &verbDB::boire,
    &verbDB::chercher,
    &verbDB::choisir,
    &verbDB::commencer,
    &verbDB::conduire,
    &verbDB::confondre,
    &verbDB::connaitre,
    &verbDB::construire,
    &verbDB::courir,
    &verbDB::couvrir,
    &verbDB::craindre,
    &verbDB::croire,
    &verbDB::cueillir,
    &verbDB::decevoir,
    &verbDB::demolir,
    &verbDB::descendre,
    &verbDB::detruire,
    &verbDB::devoir,
    &verbDB::dire,
    &verbDB::disparaitre,
    &verbDB::donner,
    &verbDB::dormir,
    &verbDB::ecrire,
    &verbDB::effacer,
    &verbDB::employer,
    &verbDB::enlever,
    &verbDB::entendre,
    &verbDB::entrer,
    &verbDB::envoyer,
    &verbDB::esperer,
    &verbDB::essayer,
    &verbDB::essuyer,
    &verbDB::eteindre,
    &verbDB::etre,
    &verbDB::exagerer,
    &verbDB::faire,
    &verbDB::falloir,
    &verbDB::fermer,
    &verbDB::finir,
    &verbDB::fuir,
    &verbDB::grimper,
    &verbDB::guerir,
    &verbDB::habiter,
    &verbDB::inventer,
    &verbDB::jeter,
    &verbDB::joindre,
    &verbDB::lancer,
    &verbDB::laver,
    &verbDB::lire,
    &verbDB::maigrir,
    &verbDB::manger,
    &verbDB::mener,
    &verbDB::mentir,
    &verbDB::mettre,
    &verbDB::monter,
    &verbDB::mourir,
    &verbDB::nager,
    &verbDB::naitre,
    &verbDB::nettoyer,
    &verbDB::obeir,
    &verbDB::offrir,
    &verbDB::ouvrir,
    &verbDB::paraitre,
    &verbDB::parler,
    &verbDB::partir,
    &verbDB::payer,
    &verbDB::peindre,
    &verbDB::perdre,
    &verbDB::peser,
    &verbDB::plaire,
    &verbDB::pleuvoir,
    &verbDB::pouvoir,
    &verbDB::prendre,
    &verbDB::produire,
    &verbDB::proteger,
    &verbDB::reagir,
    &verbDB::recevoir,
    &verbDB::reduire,
    &verbDB::reflechir,
    &verbDB::remplir,
    &verbDB::rendre,
    &verbDB::repondre,
    &verbDB::reussir,
    &verbDB::rire,
    &verbDB::rompre,
    &verbDB::sAsseoir,
    &verbDB::savoir,
    &verbDB::secher,
    &verbDB::sEnnuyer,
    &verbDB::sentir,
    &verbDB::sePlaindre,
    &verbDB::sePromener,
    &verbDB::seRejouir,
    &verbDB::servir,
    &verbDB::seTaire,
    &verbDB::sInquieter,
    &verbDB::sortir,
    &verbDB::souffrir,
    &verbDB::suffire,
    &verbDB::suivre,
    &verbDB::tenir,
    &verbDB::traduire,
    &verbDB::valoir,
    &verbDB::vendre,
    &verbDB::venir,
    &verbDB::vieillir,
    &verbDB::vivre,
    &verbDB::voir,
    &verbDB::vouloir,
};

std::vector<const verbDB::Verb*> verbDB::verbsER = {};
std::vector<const verbDB::Verb*> verbDB::verbsIR = {};
std::vector<const verbDB::Verb*> verbDB::verbsOIR = {};
std::vector<const verbDB::Verb*> verbDB::verbsRE = {};

void verbDB::initTypeVectors() {
    for (const verbDB::Verb* pVerb : verbDB::allVerbs) {
        switch (pVerb->verbType) {

            case verbDB::VerbType::er :
                verbDB::verbsER.push_back(pVerb);
                break;
        
            case verbDB::VerbType::ir :
                verbDB::verbsIR.push_back(pVerb);
                break;
            
            case verbDB::VerbType::oir :
                verbDB::verbsOIR.push_back(pVerb);
                break;
            
            case verbDB::VerbType::re :
                verbDB::verbsRE.push_back(pVerb);
                break;
        }
    }
}
