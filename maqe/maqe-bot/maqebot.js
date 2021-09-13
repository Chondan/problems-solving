const DIRECTION = {
	NORTH: "North",
	EAST: "East",
	WEST: "West",
	SOUTH: "South"
};

const COMMAND = {
	L: "L",
	R: "R",
	W: "W"
};

// Walk the robot
const walk = (position, walkAmount) => {
	const { direction } = position;
	switch (direction) {
		case DIRECTION.NORTH:
			position.y += walkAmount;
			break;
		case DIRECTION.EAST:
			position.x += walkAmount;
			break;
		case DIRECTION.WEST:
			position.x -= walkAmount;
			break;
		case DIRECTION.SOUTH:
			position.y -= walkAmount;
			break;
		default:
			break;
	}
};

// Transform face position to direction ('North', 'East', 'West', 'South')
const transformFacePositionToDirection = (position) => {
	const { face } = position;
	const facePos = face % 4;
	switch (true) {
		case facePos == 0:
			position.direction = DIRECTION.NORTH;
			break;
		case facePos == 1 || facePos == -3:
			position.direction = DIRECTION.EAST;
			break;
		case facePos == 3 || facePos == -1:
			position.direction = DIRECTION.WEST;
			break;
		case facePos == 2 || facePos == -2:
			position.direction = DIRECTION.SOUTH;
			break;
		default:
			break;
	}
};

const solution = walkingCode => {

	// face position
	//   0           0
	// 3    1    -1    -3
	//   2          -2 
	// for L -> face = face - 1
	// for R -> face = face + 1
	const position = { x: 0, y: 0, face: 0, direction: 'North' };

	for (let i = 0; i < walkingCode.length; i++) {
		const code = walkingCode[i];
		switch (code) {
			case COMMAND.L:
				position.face -= 1;
				transformFacePositionToDirection(position);
				break;
			case COMMAND.R:
				position.face += 1;
				transformFacePositionToDirection(position);
				break;
			case COMMAND.W:
				let r = i + 1;
				let walkAmount = '';
				while (r < walkingCode.length) {
					// check for a number
					if (!isNaN(walkingCode[r])) {
						walkAmount += walkingCode[r];
						r++;
					} else {
						break;
					}
				}
				// transform walkAmount to number
				walkAmount = +walkAmount;
				// walk the robot
				walk(position, walkAmount);
				break;
			default:
				continue;
		}
	}
	delete position.face;
	return position;

}

// console.log(solution("RW15RW1"));
console.log(solution("W5RW5RW2RW1R"));
console.log(solution("RRW11RLLW19RRW12LW1"));
// console.log(solution("LLW100W50RW200W10"));
// console.log(solution("LLLLLW99RRRRRW88LLLRL"));
console.log(solution("W55555RW555555W444444W1"));
