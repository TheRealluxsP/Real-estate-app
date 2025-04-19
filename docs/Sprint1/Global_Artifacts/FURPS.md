# Supplementary Specification (FURPS+)

## Functionality

_Specifies functionalities that:  
&nbsp; &nbsp; (i) are common across several US/UC;  
&nbsp; &nbsp; (ii) are not related to US/UC, namely: Audit, Reporting, and Security._

Dream House needs an application that allows clients to access properties available for **lease** or **sale**, and for company employees to carry out operations related to the real estate business, such as publishing advertisements, scheduling visits, and registering transactions (lease or sale). Property owners also use the system to sell or rent their properties.

---

### For Property Owners
1. **Property Submission**:
    - Owners can submit their properties for **sale or lease** either by visiting a Dream House branch or through the app.
    - Owners can also choose an agent to promote the property or let the system automatically assign one.

2. **Property Information Management**:
    - Owners must provide detailed information about their properties, including:
        - **Type** (apartment, house, or land).
        - **Area** (in square meters).
        - **Location** and **distance from the city center**.
        - **Requested price** and **photographs**.
    - For **houses** or **apartments**, additional information is required, such as:
        - **Number of bedrooms, bathrooms, and parking spaces**.
        - Available **equipment** (e.g., central heating or air conditioning).
    - For **houses**, details about **basements**, **attics**, and **sun exposure** must also be recorded.

3. **Commission Agreement**:
    - After submission, the real estate agent sets the **commission** (either a fixed amount or a percentage of the sale/rental price), which the owner agrees upon.

---

### For Clients
1. **Property Search**:
    - Clients can search for properties available for **lease** or **sale**.
    - They can filter properties by:
        - **Type** (apartment, house, or land).
        - **Number of rooms**.
        - Sort results by **price** or **location**.

2. **Property Details**:
    - Clients can view comprehensive details such as:
        - **Area**, **location**, **number of rooms**, and **features** like heating or air conditioning.
    - They can also access **photos** and other key property information.

3. **Scheduling Visits**:
    - To check a property's conditions, clients can request a visit by selecting preferred **dates** and **times**.
    - The agent managing the property receives the request, checks availability, and registers the visit in the system.
    - The system then sends an **SMS notification** to the client with the visit details.

4. **Purchasing or Leasing Requests**:
    - Clients can submit a **purchase** or **lease request** to the agent.
    - After review, the agent **accepts** or **rejects** the request. If accepted, the property will be **removed from public listings**.

5. **Client Registration**:
    - Clients must register by providing:
        - **Name**, **citizen’s card number**, **tax identification number (TIF)**, **email address**, and **contact telephone number**.
    - The system automatically assigns an **internal code** to each client for future interactions.

---

### For Company Employees (Real Estate Agents and Managers)
1. **Property Management**:
    - Agents can publish advertisements for properties provided by owners.
    - They enter detailed property information, including:
        - **Type**, **size**, **price**, **location**, and specific features (e.g., basement, sun exposure).

2. **Commission Management**:
    - Upon receiving a new property submission, the agent defines the **commission** (fixed amount or percentage) and publishes the offer.
    - The commission is **not visible** to clients.

3. **Scheduling Management**:
    - The agent managing the property receives visit requests, checks availability, and registers the scheduling in the system.

4. **Transaction Processing**:
    - Agents review client **purchase** or **lease requests** and decide whether to **accept** or **reject** them.
    - If accepted, the property is **removed from the listings** available to clients.

5. **Store Network Management**:
    - The **store network manager** is responsible for:
        - Registering branches, including **branch details** (code, name, address, opening/closing times).
        - Managing agents by recording **name**, **citizen’s card number**, **email address**, **telephone number**, and **branch assignment**.
    - A branch is characterized by its **code**, **designation**, **address**, and **operating hours**.

---

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
---
**Help and Documentation** 
- In the future, tooltips and a help section should be added to guide users in performing key operations, such as adding property details or managing client requests.
---
**Consistency and Standards** 
- The application should adhere to common interface conventions, such as uniform commands for adding, editing, and viewing property information, maintaining a consistent user experience across all interactions.

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
---
**System Availability**
- Availability must be higher than 99% per year, considering that Dream House needs persistent access to real-time property data.
---
**Resources Management**
- As the system core is meant to be reusable, it is of utmost importance to optimize its utilization of available resources, such as RAM and CPU processing.
Therefore, it should be possible to handle large amounts of data with no hassle and maintain compatibility between all kinds of working environments.


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