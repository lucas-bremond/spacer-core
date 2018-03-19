# Types

from SpacerCorePy import Types

## Integer

assert Types.Integer(0) == 0
assert Types.Integer(123) == 123
assert Types.Integer(+123) == +123
assert Types.Integer(-123) == -123

assert Types.Integer(0).getString() == "0"
assert Types.Integer(123).getString() == "123"
assert Types.Integer(+123).getString() == "123"
assert Types.Integer(-123).getString() == "-123"

## Real