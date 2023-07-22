#include "../include/TinyUI.h"

namespace tiny {

    TinyUI *TinyUI::instance = nullptr;

    TinyUI::TinyUI(binding::Binding *binding) :
            mBinding(binding) {

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

    std::shared_ptr<binding::Binding> TinyUI::binding() {
        return mBinding;
    }

} // tiny
