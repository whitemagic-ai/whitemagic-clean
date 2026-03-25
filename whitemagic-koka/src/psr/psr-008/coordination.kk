// coordination - Koka Migration
// Coordination
// Effect handlers for type-safe coordination

module coordination

effect coordination_effect {
    fun process(data: string): string
    fun get_state(): int
}

fun coordination_handler(action: () -> <coordination_effect> a): a {
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
