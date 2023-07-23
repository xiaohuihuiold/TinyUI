#include "TinyUI.h"
#include <utility>

namespace tiny {

    TinyUI *TinyUI::instance = nullptr;

    TinyUI::TinyUI(std::shared_ptr<binding::Binding> binding) :
            binding(std::move(binding)) {

    }

    TinyUI *TinyUI::begin(std::shared_ptr<binding::TimerBinding> timerBinding,
                          std::shared_ptr<binding::RenderBinding> renderBinding) {
        if (timerBinding == nullptr || renderBinding == nullptr) {
            return nullptr;
        }
        if (instance == nullptr) {
            instance = new TinyUI(
                    std::make_shared<binding::Binding>(std::move(timerBinding), std::move(renderBinding)));
        }
        return instance;
    }

    TinyUI *TinyUI::get() {
        return instance;
    }

    std::shared_ptr<painting::Canvas> TinyUI::beginCanvas() {
        return std::make_shared<painting::Canvas>(this);
    }

    void TinyUI::beginFrame() {
        binding->render->beginFrame();
    }

    void TinyUI::endFrame() {
        binding->render->endFrame();
    }

} // tiny
