"""Source-derived float32 timing examples, not Unity/game runtime observations."""
import struct


def f32(value):
    return struct.unpack("<f", struct.pack("<f", value))[0]


def simulate(fps, admission_stride, frames=240):
    dt, threshold, skipped, clip_progress = f32(1 / 60), f32(1 / fps), f32(0), f32(0)
    events = {"male": f32(0.38333332538604736), "female_or_sitting": f32(0.6666666865348816)}
    crossings, updates = {}, []
    for frame in range(1, frames + 1):
        if frame % admission_stride:
            continue
        skipped = f32(skipped + dt)
        if skipped < threshold:
            continue
        previous = clip_progress
        clip_progress = f32(clip_progress + skipped)
        updates.append({"frame": frame, "argument": skipped, "accumulated_progress": clip_progress})
        for name, event in events.items():
            if name not in crossings and previous < event <= clip_progress:
                crossings[name] = {"frame": frame, "nominal_wall_seconds": frame / 60,
                                   "progress_crossing_only": True}
        skipped = f32(0)
    return {"fps": fps, "admission_stride": admission_stride, "host_delta": dt,
            "manual_update_count": len(updates), "first_updates": updates[:4], "event_threshold_crossings": crossings}


def examples():
    result = [simulate(fps, stride) for stride in (1, 3) for fps in (30, 10, 5, 2)]
    # Meaningful counterexamples to forwarding a fixed interval or lost overshoot.
    total = f32(f32(0.3) + f32(0.3))
    assert total > f32(0.5) and total == f32(0.6000000238418579)
    all_frames = simulate(2, 1)
    one_in_three = simulate(2, 3)
    assert all_frames["event_threshold_crossings"]["male"]["frame"] == 30
    assert one_in_three["event_threshold_crossings"]["male"]["frame"] == 90
    return {"kind": "source-derived conditional arithmetic examples", "scenarios": result,
            "overshoot_example": {"fps": 2, "admitted_deltas": [f32(0.3), f32(0.3)], "forwarded_sum": total},
            "assumptions": ["Already in manual mode; startup guards omitted; constant 60Hz host with positive deltaTime.",
                "Stride3 models only the observed upper caller gate; other guards, state changes and external speed changes omitted.",
                "Progress thresholds are arithmetic crossings only. Unity event evaluation, transitions, culling, callback dispatch and sound are not simulated.",
                "Animation speed and state speed are assumed one; no clock pause, mode switching or model destruction."]}
