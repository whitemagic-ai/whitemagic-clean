"""War Room — Shadow Clone Army, Imperial Doctrine, Art of War, Fool's Guard."""
import logging
from typing import Any

logger = logging.getLogger(__name__)


# ═══════════════════════════════════════════════════════════════════════════════
# War Room Status & Management
# ═══════════════════════════════════════════════════════════════════════════════

def handle_war_room_status(**kwargs: Any) -> dict[str, Any]:
    """Get War Room and Shadow Clone Army status."""
    try:
        from whitemagic.agents.war_room import WarRoom
        war_room = WarRoom()
        return {
            "status": "success",
            **war_room.get_status()
        }
    except ImportError:
        return {
            "status": "success",
            "war_room_active": False,
            "active_campaigns": 0,
            "deployed_clones": 0,
            "phase": "dormant",
            "note": "War Room module archived - no active campaigns"
        }
    except Exception as e:
        return {"status": "error", "error": str(e)}


def handle_war_room_plan(**kwargs: Any) -> dict[str, Any]:
    """Create a strategic plan in the War Room."""
    try:
        from whitemagic.agents.war_room import WarRoom
        war_room = WarRoom()
        
        objective = kwargs.get("objective", "")
        resources = kwargs.get("resources", {})
        
        if not objective:
            return {"status": "error", "error": "objective required"}
        
        plan = war_room.plan(objective=objective, resources=resources)
        return {
            "status": "success",
            "plan_created": True,
            "objective": objective,
            **plan
        }
    except ImportError:
        return {
            "status": "success",
            "plan_created": False,
            "objective": kwargs.get("objective", ""),
            "note": "War Room planner archived - manual planning required"
        }
    except Exception as e:
        return {"status": "error", "error": str(e)}


def handle_war_room_execute(**kwargs: Any) -> dict[str, Any]:
    """Execute a plan in the War Room."""
    try:
        from whitemagic.agents.war_room import WarRoom
        war_room = WarRoom()
        
        plan_id = kwargs.get("plan_id")
        if not plan_id:
            return {"status": "error", "error": "plan_id required"}
        
        result = war_room.execute(plan_id=plan_id)
        return {
            "status": "success",
            "plan_id": plan_id,
            **result
        }
    except ImportError:
        return {
            "status": "success",
            "plan_id": kwargs.get("plan_id"),
            "executed": False,
            "note": "War Room executor archived"
        }
    except Exception as e:
        return {"status": "error", "error": str(e)}


def handle_war_room_hierarchy(**kwargs: Any) -> dict[str, Any]:
    """Get clone army hierarchy."""
    try:
        from whitemagic.agents.war_room import WarRoom
        war_room = WarRoom()
        return {
            "status": "success",
            "hierarchy": war_room.get_hierarchy()
        }
    except ImportError:
        return {
            "status": "success",
            "hierarchy": {},
            "note": "War Room hierarchy archived"
        }
    except Exception as e:
        return {"status": "error", "error": str(e)}


def handle_war_room_campaigns(**kwargs: Any) -> dict[str, Any]:
    """List active campaigns in the War Room."""
    try:
        from whitemagic.agents.war_room import WarRoom
        war_room = WarRoom()
        
        status_filter = kwargs.get("status", "all")
        campaigns = war_room.list_campaigns(status=status_filter)
        
        return {
            "status": "success",
            "campaigns": campaigns,
            "count": len(campaigns),
            "filter": status_filter
        }
    except ImportError:
        return {
            "status": "success",
            "campaigns": [],
            "count": 0,
            "note": "War Room campaigns archived"
        }
    except Exception as e:
        return {"status": "error", "error": str(e)}


def handle_war_room_phase(**kwargs: Any) -> dict[str, Any]:
    """Get or set War Room phase."""
    try:
        from whitemagic.agents.war_room import WarRoom
        war_room = WarRoom()
        
        new_phase = kwargs.get("phase")
        
        if new_phase:
            war_room.set_phase(new_phase)
        
        return {
            "status": "success",
            "phase": war_room.get_phase(),
            "phase_changed": new_phase is not None
        }
    except ImportError:
        return {
            "status": "success",
            "phase": "dormant",
            "note": "War Room phase control archived"
        }
    except Exception as e:
        return {"status": "error", "error": str(e)}


# ═══════════════════════════════════════════════════════════════════════════════
# Imperial Doctrine (36 Stratagems)
# ═══════════════════════════════════════════════════════════════════════════════

def handle_doctrine_summary(**kwargs: Any) -> dict[str, Any]:
    """Get summary of Imperial Doctrine (36 Stratagems)."""
    try:
        from whitemagic.agents.doctrine import ImperialDoctrine
        doctrine = ImperialDoctrine()
        return {
            "status": "success",
            **doctrine.get_summary()
        }
    except (ImportError, AttributeError):
        # Module doesn't exist or get_summary doesn't exist - use fallback
        stratagems = [
            {"category": "Winning Stratagems", "stratagems": [
                "Cross the sea without the emperor's knowledge",
                "Besiege Wei to rescue Zhao",
                "Kill with a borrowed knife",
                "Wait at leisure while the enemy labors",
                "Loot a burning house",
                "Make a sound in the east, strike in the west"
            ]},
            {"category": "Enemy Dealing Stratagems", "stratagems": [
                "Create something from nothing",
                "Openly repair the gallery roads, secretly march to Chencang",
                "Watch the fires burning across the river",
                "Hide a knife behind a smile",
                "Sacrifice the plum tree to preserve the peach tree",
                "Take the opportunity to pilfer a goat"
            ]},
            {"category": "Offensive Stratagems", "stratagems": [
                "Stomp the grass to scare the snake",
                "Borrow a corpse to resurrect the soul",
                "Lure the tiger down the mountain",
                "Let the enemy's own spy sow discord",
                "Inflict injury on oneself to win the enemy's trust",
                "Chain stratagems"
            ]},
            {"category": "Muddy Waters Stratagems", "stratagems": [
                "Remove the firewood from under the pot",
                "Disturb the water and catch a fish",
                "Slough off the cicada's golden shell",
                "Shut the door to catch the thief",
                "Befriend a distant state while attacking a neighbor",
                "Obtain safe passage to conquer the Guo"
            ]},
            {"category": "Combination Stratagems", "stratagems": [
                "Replace the beams with rotten timbers",
                "Point at the mulberry tree while cursing the locust tree",
                "Feign madness but keep your balance",
                "Remove the ladder when the enemy has ascended to the roof",
                "Make the host and the guest exchange roles",
                "Use a woman to ensnare a man"
            ]},
            {"category": "Desperate Stratagems", "stratagems": [
                "The empty fort strategy",
                "Let the enemy's spy go back to report false information",
                "Wrap the corpse in skin of a beauty",
                "The honey trap",
                "The strategy of mutual destruction",
                "If all else fails, retreat"
            ]}
        ]
        return {
            "status": "success",
            "doctrine": "36 Stratagems (San Shi Liu Ji)",
            "categories": 6,
            "total_stratagems": 36,
            "stratagems": stratagems,
            "note": "Classical Chinese military doctrine"
        }
    except Exception as e:
        return {"status": "error", "error": str(e)}


def handle_doctrine_stratagems(**kwargs: Any) -> dict[str, Any]:
    """Get specific stratagems by category or situation."""
    try:
        from whitemagic.agents.doctrine import ImperialDoctrine
        doctrine = ImperialDoctrine()
        
        category = kwargs.get("category")
        situation = kwargs.get("situation", "")
        
        stratagems = doctrine.get_stratagems(category=category, situation=situation)
        return {
            "status": "success",
            "category": category,
            "situation": situation,
            "stratagems": stratagems,
            "count": len(stratagems)
        }
    except ImportError:
        return {
            "status": "success",
            "category": kwargs.get("category"),
            "situation": kwargs.get("situation", ""),
            "stratagems": [],
            "note": "Doctrine module archived - use classical 36 Stratagems"
        }
    except Exception as e:
        return {"status": "error", "error": str(e)}


def handle_doctrine_force(**kwargs: Any) -> dict[str, Any]:
    """Apply doctrine force to a situation."""
    try:
        from whitemagic.agents.doctrine import ImperialDoctrine
        doctrine = ImperialDoctrine()
        
        stratagem_id = kwargs.get("stratagem_id")
        target = kwargs.get("target", "")
        
        if not stratagem_id:
            return {"status": "error", "error": "stratagem_id required"}
        
        result = doctrine.apply_force(stratagem_id=stratagem_id, target=target)
        return {
            "status": "success",
            "stratagem_id": stratagem_id,
            "target": target,
            **result
        }
    except ImportError:
        return {
            "status": "success",
            "stratagem_id": kwargs.get("stratagem_id"),
            "target": kwargs.get("target", ""),
            "force_applied": False,
            "note": "Doctrine force application archived"
        }
    except Exception as e:
        return {"status": "error", "error": str(e)}


# ═══════════════════════════════════════════════════════════════════════════════
# Art of War Engine
# ═══════════════════════════════════════════════════════════════════════════════

def handle_art_of_war_wisdom(**kwargs: Any) -> dict[str, Any]:
    """Get Art of War wisdom for a situation."""
    try:
        from whitemagic.agents.art_of_war import ArtOfWarEngine
        engine = ArtOfWarEngine()
        
        situation = kwargs.get("situation", "")
        chapter = kwargs.get("chapter")
        
        wisdom = engine.get_wisdom(situation=situation, chapter=chapter)
        return {
            "status": "success",
            "situation": situation,
            **wisdom
        }
    except ImportError:
        # Fallback to classical Art of War quotes
        quotes = [
            "The supreme art of war is to subdue the enemy without fighting.",
            "All warfare is based on deception.",
            "If you know the enemy and know yourself, you need not fear the result of a hundred battles.",
            "Victorious warriors win first and then go to war, while defeated warriors go to war first and then seek to win.",
            "In war, the way is to avoid what is strong and to strike at what is weak.",
            "Opportunities multiply as they are seized.",
            "The greatest victory is that which requires no battle.",
            "Know yourself and you will win all battles."
        ]
        import random
        return {
            "status": "success",
            "wisdom": random.choice(quotes),
            "source": "Sun Tzu - The Art of War",
            "note": "Classical Art of War wisdom"
        }
    except Exception as e:
        return {"status": "error", "error": str(e)}


def handle_art_of_war_terrain(**kwargs: Any) -> dict[str, Any]:
    """Analyze terrain using Art of War principles."""
    try:
        from whitemagic.agents.art_of_war import ArtOfWarEngine
        engine = ArtOfWarEngine()
        
        terrain_type = kwargs.get("terrain_type", "")
        context = kwargs.get("context", {})
        
        analysis = engine.analyze_terrain(terrain_type=terrain_type, context=context)
        return {
            "status": "success",
            "terrain_type": terrain_type,
            **analysis
        }
    except ImportError:
        return {
            "status": "success",
            "terrain_type": kwargs.get("terrain_type", ""),
            "nine_terrains": ["dispersive", "facile", "contentious", "open", "intersecting", "heavy", "bad", "encircled", "death"],
            "note": "Terrain analysis module archived"
        }
    except Exception as e:
        return {"status": "error", "error": str(e)}


def handle_art_of_war_campaign(**kwargs: Any) -> dict[str, Any]:
    """Plan a campaign using Art of War principles."""
    try:
        from whitemagic.agents.art_of_war import ArtOfWarEngine
        engine = ArtOfWarEngine()
        
        objective = kwargs.get("objective", "")
        resources = kwargs.get("resources", {})
        
        if not objective:
            return {"status": "error", "error": "objective required"}
        
        campaign = engine.plan_campaign(objective=objective, resources=resources)
        return {
            "status": "success",
            "objective": objective,
            **campaign
        }
    except ImportError:
        return {
            "status": "success",
            "objective": kwargs.get("objective", ""),
            "campaign_phases": ["planning", "preparation", "engagement", "victory"],
            "note": "Campaign planner archived"
        }
    except Exception as e:
        return {"status": "error", "error": str(e)}


def handle_art_of_war_chapter(**kwargs: Any) -> dict[str, Any]:
    """Get specific chapter from Art of War."""
    try:
        from whitemagic.agents.art_of_war import ArtOfWarEngine
        engine = ArtOfWarEngine()
        
        chapter_num = kwargs.get("chapter", 1)
        content = engine.get_chapter(chapter_num)
        return {
            "status": "success",
            "chapter": chapter_num,
            **content
        }
    except ImportError:
        chapters = [
            "Laying Plans",
            "Waging War",
            "Attack by Stratagem",
            "Tactical Dispositions",
            "Energy",
            "Weak Points and Strong",
            "Maneuvering",
            "Variation of Tactics",
            "The Army on the March",
            "Terrain",
            "The Nine Situations",
            "The Attack by Fire",
            "The Use of Spies"
        ]
        chapter_idx = kwargs.get("chapter", 1) - 1
        if 0 <= chapter_idx < len(chapters):
            return {
                "status": "success",
                "chapter": kwargs.get("chapter", 1),
                "title": chapters[chapter_idx],
                "note": "Classical chapter listing"
            }
        return {
            "status": "error",
            "error": f"Invalid chapter number. Valid range: 1-{len(chapters)}"
        }
    except Exception as e:
        return {"status": "error", "error": str(e)}


# ═══════════════════════════════════════════════════════════════════════════════
# Fool's Guard / Ralph Wiggum Anti-Groupthink
# ═══════════════════════════════════════════════════════════════════════════════

def handle_fool_guard_status(**kwargs: Any) -> dict[str, Any]:
    """Get Fool's Guard anti-groupthink system status."""
    try:
        from whitemagic.agents.fool_guard import FoolGuard
        guard = FoolGuard()
        return {
            "status": "success",
            **guard.get_status()
        }
    except ImportError:
        return {
            "status": "success",
            "guard_active": True,
            "ralph_mode": "ready",
            "dare_to_die_count": 0,
            "groupthink_checks": 0,
            "note": "Fool's Guard (Ralph Wiggum mode) - preventing groupthink"
        }
    except Exception as e:
        return {"status": "error", "error": str(e)}


def handle_fool_guard_dare_to_die(**kwargs: Any) -> dict[str, Any]:
    """Dare to die - challenge assumptions aggressively."""
    try:
        from whitemagic.agents.fool_guard import FoolGuard
        guard = FoolGuard()
        
        assumption = kwargs.get("assumption", "")
        context = kwargs.get("context", {})
        
        if not assumption:
            return {"status": "error", "error": "assumption required"}
        
        challenge = guard.dare_to_die(assumption=assumption, context=context)
        return {
            "status": "success",
            "assumption": assumption,
            **challenge
        }
    except ImportError:
        return {
            "status": "success",
            "assumption": kwargs.get("assumption", ""),
            "challenged": True,
            "perspective": "What if the opposite is true?",
            "note": "Dare to die - question everything"
        }
    except Exception as e:
        return {"status": "error", "error": str(e)}


def handle_fool_guard_ralph(**kwargs: Any) -> dict[str, Any]:
    """Activate Ralph Wiggum mode - innocent questions that break groupthink."""
    try:
        from whitemagic.agents.fool_guard import FoolGuard
        guard = FoolGuard()
        
        topic = kwargs.get("topic", "")
        question_count = kwargs.get("question_count", 3)
        
        ralph_questions = guard.ralph_mode(topic=topic, count=question_count)
        return {
            "status": "success",
            "topic": topic,
            **ralph_questions
        }
    except ImportError:
        # Classic Ralph Wiggum-style innocent questions
        questions = [
            "Why is that?",
            "But what if it's not?",
            "Is that really true?",
            "What does that mean?",
            "How do we know?",
            "What if we did the opposite?",
            "Can you explain that to me like I'm five?",
            "What would happen if we didn't do that?"
        ]
        import random
        return {
            "status": "success",
            "topic": kwargs.get("topic", ""),
            "ralph_mode": "active",
            "questions": random.sample(questions, min(kwargs.get("question_count", 3), len(questions))),
            "note": "Ralph Wiggum mode - innocent questions to break groupthink"
        }
    except Exception as e:
        return {"status": "error", "error": str(e)}
