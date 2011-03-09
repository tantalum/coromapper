define grippybot position (
	size [1.25 1 1]
	origin [0.125 0 0 0]
	drive "diff"

	# Main Robot body
	block (
		points 6 
		point[0] [0 0]
		point[1] [0.75 0]
		point[2] [1 0.25]
		point[3] [1 0.75]
		point[4] [0.75 1]
		point[5] [0 1]
		z [0 1]
	)

	# Bottom Gripper
	block (
		points 12
		point[0] [1 0.35]
		point[1] [1.10 0.35]
		point[2] [1.10 0.30]
		point[3] [1.25 0.30]
		point[4] [1.25 0.35]
		point[5] [1.15 0.35]
		point[6] [1.15 0.40]
		point[7] [1.25 0.40]
		point[8] [1.25 0.45]
		point[9] [1.10 0.45]
		point[10] [1.10 0.40]
		point[11] [1 0.40]
	)

	# Top Gripper
	block (
		points 12
		point[0] [1 0.60]
		point[1] [1.10 0.60]
		point[2] [1.10 0.55]
		point[3] [1.25 0.55]
		point[4] [1.25 0.60]
		point[5] [1.15 0.60]
		point[6] [1.15 0.65]
		point[7] [1.25 0.65]
		point[8] [1.25 0.70]
		point[9] [1.10 0.70]
		point[10] [1.10 0.65]
		point[11] [1 0.65]
	)
)
