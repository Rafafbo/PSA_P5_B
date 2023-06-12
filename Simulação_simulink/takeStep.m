function C = takeStep(stepLength, stepVelocity,stepHeight,stepClearance)
C = zeros(6,2*size(stepLength:-0.5:-stepLength,2));
idx = 1;
    for i = stepLength:-0.5:-stepLength
        Q_r = pos(i, stepHeight, 'r');
        Q_l = pos(-i, stepHeight - stepClearance, 'l');
        pause(stepVelocity/1000);
        C(:, idx) = [Q_l(1:3,1); Q_r(4:6,1)];
        idx = idx + 1;
    end

    for i = stepLength:-0.5:-stepLength
        Q_r = pos(-i, stepHeight - stepClearance, 'r');
        Q_l = pos(i, stepHeight, 'l');
        pause(stepVelocity/1000);
        C(:, idx) = [Q_l(1:3,1); Q_r(4:6,1)];
        idx = idx + 1;
    end

end