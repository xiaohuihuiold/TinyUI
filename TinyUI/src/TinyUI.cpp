#include "TinyUI.h"

namespace tiny {

    TinyUI *TinyUI::instance = nullptr;

    TinyUI::TinyUI(binding::Binding *binding) :
            binding(binding) {

    }

    TinyUI *TinyUI::begin(binding::TimerBinding *timerBinding) {
        if (instance == nullptr) {
            instance = new TinyUI(new binding::Binding(timerBinding));
        }
        return instance;
    }

    TinyUI *TinyUI::get() {
        return instance;
    }

} // tiny
