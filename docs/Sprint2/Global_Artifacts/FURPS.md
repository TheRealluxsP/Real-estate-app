# Supplementary Specification (FURPS+)

## Functionality

_Specifies functionalities that:  
&nbsp; &nbsp; (i) are common across several US/UC;  
&nbsp; &nbsp; (ii) are not related to US/UC, namely: Audit, Reporting, and Security._

Dream House needs an application that allows clients to access properties available for **lease** or **sale**, and for company employees to carry out operations related to the real estate business, such as publishing advertisements, scheduling visits, and registering transactions (lease or sale). Property owners also use the system to sell or rent their properties.

(fill in here)

### Authentication
- **All users** must authenticate to use the system. However, for now, the authentication process can be **simulated or mocked**.

## Usability 

_Evaluates the user interface. It has several subcategories,
among them: error prevention; interface aesthetics and design; help and
documentation; consistency and standards._

**Error Prevention** 
- The system will use form validation to prevent data entry errors (e.g., incorrect formatting of dates or missing required fields like property price).
---
**Interface Aesthetics and Design** 
- While the current focus is on core application development, the basic console UI should follow a clear and consistent layout to ensure ease of navigation during demonstrations. 
- The user interface must be simple, intuitive, and consistent.
---
**Help and Documentation** 
- In the future, tooltips and a help section should be added to guide users in performing key operations, such as adding property details or managing client requests.
- The application must be provided with a user manual.
---
**Consistency and Standards** 
- The application should adhere to common interface conventions, such as uniform commands for adding, editing, and viewing property information, maintaining a consistent user experience across all interactions.
- The team must adopt recognized coding standards (e.g. CamelCase).



## Reliability
_Refers to the integrity, compliance and interoperability of the software. The requirements to be considered are: frequency and severity of failure, possibility of recovery, possibility of prediction, accuracy, average time between failures._

**Frequency and Severity of Failure** 
- Overall system availability must be higher than 99% per year. The impact on operations, when such a failure case occurs, should be minimal.
---
**Possibility of Recovery**
- The system should start up in less than 10 seconds and whenever the system fails, there should be no
  data loss.
---
**Accuracy**
- Property listings, client information, and transaction details must be stored and displayed accurately without omissions or corruption.
---
**Average Time Between Failures**
- At certain times of the day, it is expected that the system will be overloaded. To avoid
  potential problems, the system must be prepared so that the response time is at maximum of 5
  seconds regardless of the existing load.

## Performance
_Evaluates the performance requirements of the software, namely: response time, start-up time, recovery time, memory consumption, CPU usage, load capacity and application availability._

**Start-up Time**
- The system should start up in less than 10 seconds and whenever the system fails, there should be no
  data loss.
---
**Response Time**
- At certain times of the day, it is expected that the system will be overloaded. To avoid
  potential problems, the system must be prepared so that the response time is at maximum of 5
  seconds regardless of the existing load.
- Any interaction between a
  user and the system shall have a maximum response time of 3 seconds.
---
**System Availability**
- Availability must be higher than 99% per year, considering that Dream House needs persistent access to real-time property data.
---
**Resources Management**
- As the system core is meant to be reusable, it is of utmost importance to optimize its utilization of available resources, such as RAM and CPU processing.
Therefore, it should be possible to handle large amounts of data with no hassle and maintain compatibility between all kinds of working environments.
- The application will be deployed to machines with 8 GB of RAM.


## Supportability
_The supportability requirements gathers several characteristics, such as:
testability, adaptability, maintainability, compatibility,
configurability, instalability, scalability and more._ 

**Testability**
- The usage of the **Google Testing Framework** will help automate and simplify the testing process with both unit and regression tests.
---
**Adaptability**
- A flexible system is a must when dealing with the changing nature of data and growth of a company.
---
**Maintainability**
- To extend functionality, it is important to keep on with a modular design and follow a coherent development plan.
---
**Compatibility**
- The system must support various databases (relational, NoSQL, or in-memory), and integration with future user interfaces (e.g., web or mobile apps).
---
**Configurability** 
- System settings like commission percentages and branch data must be configurable without requiring code changes.
---
**Scalability**
- As the Dream House network grows, the system must scale effectively to handle new branches and more users.

## +

### Design Constraints

_Specifies or constraints the system design process. Examples may include: programming languages, software process, mandatory standards/patterns, use of development tools, class library, etc._

- Due to the sensitivity and criticality of the core application it is required to be
developed in **C++** language using the **CLion IDE**, preferably.
- All project artifacts (including code) must be developed in **English**.
- Adoption of automatic regression
  tests, using the **Google Testing Framework**, is also strongly recommended/valued.

### Implementation Constraints

_Specifies or constraints the code or construction of a system such
such as: mandatory standards/patterns, implementation languages,
database integrity, resource limits, operating system._

- It is important that the system is prepared to easily support data persistence on multiple target systems as, for instance, relational
databases, NoSQL databases or in memory databases.

### Interface Constraints
_Specifies or constraints the features inherent to the interaction of the
system being developed with other external systems._

- A core server-side application responsible for maintaining and persisting all data required by
  the system (e.g. company branches, clients, advertisements) as well as for ensuring applicable
  business logic (e.g. showing/hiding a given advertisement). Moreover, this application
  provides several API to support the development of user applications.
- Several client-side applications responsible for interaction with end-users as, for instance, the
  Dream House staff, or the clients. These applications rely on one of the several API provided
  by the server-side application.
- Despite being envisioned, at least, one user application per
  platform (i.e. web, iOS, Android), at this moment, its development is out of scope, **excepting
  a basic UI console application for demo purposing.**
- In addition, generic HTTP client
  applications (e.g. Postman) can be used to verify and validate the API made available.

### Physical Constraints

_Specifies a limitation or physical requirement regarding the hardware used to house the system, as for example: material, shape, size or weight._

- The system should support all the defined requirements, including support for database operations and scalability to effectively handle new branches and more users.