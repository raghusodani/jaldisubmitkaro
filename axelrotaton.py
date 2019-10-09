from math import sin, cos, radians, pi, atan2, degrees

def angle_to(p1, p2, rotation=0, clockwise=False):
    if abs(rotation) > 360:
        rotation %= 360
    p2 = list(p2)
    p2[0] = p2[0] - p1[0]
    p2[1] = p2[1] - p1[1]

    angle = degrees(atan2(p2[1], p2[0]))
    if clockwise:
        angle -= rotation
        return angle if angle > 0 else angle + 360
    else:
        angle = (360 - angle if angle > 0 else -1 * angle) - rotation
        return angle if angle > 0 else angle + 360

def point_pos(origin, amplitude, angle, rotation=0, clockwise=False):
    if abs(rotation) > 360:
        rotation %= 360
    if clockwise:
        rotation *= -1
    if clockwise:
        angle -= rotation
        angle = angle if angle > 0 else angle + 360
    else:
        angle = (360 - angle if angle > 0 else -1 * angle) - rotation
        angle = angle if angle > 0 else angle + 360

    theta_rad = radians(angle)
    return int(origin[0] + amplitude * cos(theta_rad)), int(origin[1] + amplitude * sin(theta_rad))
