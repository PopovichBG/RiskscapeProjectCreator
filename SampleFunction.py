from nz.org.riskscape.engine.types import Types, Nullable, Struct
from nz.org.riskscape.engine.function import Maths

# This is a unique ID and a description for the RiskScape function
ID = 'A_Sample_Function'
DESCRIPTION = 'A simple sample exposure function to exemplify RiskScape Python syntax'

# Here we define the type related to the function's output.  Whatever is contained here will be output from RiskScape.
RETURN_TYPE = Struct.StructBuilder() \
	.and("Exposure", Types.INTEGER) \
	.build()

# Argument types for the function.  However many arguments the function requires, an equal number of return types are defined here.
# For example, if the function requires an asset and a hazard, there must be two argument types defined, one pertaining to the 
# asset and one to the hazard.  These argument types must be in the same order as the arguments are defined for the function.
ARGUMENT_TYPES = ['ASampleAsset', 'ASampleHazard']

# Begin function definition
def function(asset, hazard):

	# Beginning of the code of the function.  Whatever is contained here is what calculation will be performed by RiskScape
	exposure = 0
	if hazard is not none:
		if hazard.get('Depth') > 0.0:
			exposure = 1

	#Define a blank array and fill it with the return variables
	result = {}
	# The return type of the function defined one output called "Exposure".  The data for this type is 
	# stored in the variable "exposure".  This is assigned to the output like below:
	result['Exposure'] = exposure