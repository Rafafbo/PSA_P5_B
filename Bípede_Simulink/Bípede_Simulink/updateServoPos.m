function B = updateServoPos(target1, target2, target3, leg)

hipLOffset = pi/2;
kneeLOffset = pi/2;
ankleLOffset = -pi/2;
hipROffset = -pi/2;
kneeROffset = -pi/2;
ankleROffset = pi/2;

Q = zeros (6,1);

    if leg == 'l'
        hipL = hipLOffset - target1;
        kneeL = kneeLOffset - target2;
        ankleL = 2*ankleLOffset - target3;
        Q(1,1) = hipL;
        Q(2,1) = kneeL;
        Q(3,1) = ankleL;
    elseif leg == 'r'
        hipR = hipROffset + target1;
        kneeR = kneeROffset + target2;
        ankleR = target3;
        Q(4,1) = hipR;
        Q(5,1) = kneeR;
        Q(6,1) = ankleR;
    end
    B = Q;
end
