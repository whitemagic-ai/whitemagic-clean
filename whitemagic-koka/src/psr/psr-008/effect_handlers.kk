// effect_handlers - Koka Migration
// Effect system
// Effect handlers for type-safe coordination

module effect_handlers

effect effect_handlers_effect {
    fun process(data: string): string
    fun get_state(): int
}

fun effect_handlers_handler(action: () -> <effect_handlers_effect> a): a {
    with handler {
        fun process(data) {
            // TODO: Implement effect handler
            data
        }
        fun get_state() {
            0
        }
    }
    action()
}
