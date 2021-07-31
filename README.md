# Stream_Selection
Simulates stream selection process for engineering level 2 at McMaster University

This project consists of two parts: Student Generation and Stream Selection

### Student Generation
* Generates students with student number, GPA and choice ranking
* GPA is randomly generated with a normal distribution
* choices are randomly generated and checked for uniqueness

### Stream Selection
* Highest GPA student gets first choice, continues going down list until stream cap is reached
* If cap is reached, and there are still students with the same GPA as the last accepted student, ALL students with that GPA are removed from that stream
* This counter applies to Management and Society simultaneously
