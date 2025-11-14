# cpp-android-budget-app
Native C++ Application (NDK) of budget management for Android.

## 🚀 MoSCoW Matrix (Project Prioritization)

Here is the feature breakdown for Version 1.0 (Local MVP).

| Priority           | Feature Description                                                                                                                                          |
|:-------------------|:-------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 🟢 **Must Have** ✅ | **(Technical) C++ Core:** All business logic (calculations, data management) **must** be implemented in native C++ (C++17/20).                               |
| 🟢 **Must Have** ✅ | **(Technical) JNI Bridge:** A JNI interface (`native-lib.cpp`) **must** exist for UI (Kotlin) <-> C++ communication.                                         |
| 🟢 **Must Have**   | **(Technical) CMake Compilation:** The project **must** be compiled entirely via `CMakeLists.txt`.                                                           |
| 🟢 **Must Have**   | **(Technical) Data Persistence:** Accounts and transactions **must** be saved persistently on the device (via **SQLite** used from C++).                     |
| 🟢 **Must Have**   | **(Functional) Account Management:** The user **must** be able to create, view, and delete simulated bank accounts (e.g., Checking, Savings).                |
| 🟢 **Must Have**   | **(Functional) Transaction Entry:** The user **must** be able to manually add transactions (income/expense) to an account.                                   |
| 🟢 **Must Have**   | **(Functional) Balance Calculation:** The account balance **must** update automatically after each transaction.                                              |
| 🔵 **Should Have** | **(Functional) Recurring Transactions:** The user **should** be able to mark a transaction as "recurring" (e.g., salary, rent) for forecasting.              |
| 🔵 **Should Have** | **(Functional) Budget Forecasting:** The app **should** be able to calculate a "projected balance" or "money left to spend" based on recurring transactions. |
| 🔵 **Should Have** | **(Functional) Categorization:** The user **should** be able to assign a category to their expenses (e.g., Food, Transport).                                 |
| 🔵 **Should Have** | **(Functional) Edit/Delete:** The user **should** be able to edit or delete an existing transaction.                                                         |
| 🟡 **Could Have**  | **(UI) Graphical Visualization:** The app **could** display a simple chart (e.g., pie chart) of expenses by category.                                        |
| 🟡 **Could Have**  | **(Functional) Data Export:** The user **could** export their data (e.g., as CSV).                                                                           |
| 🟡 **Could Have**  | **(UI) Dark Theme:** The app **could** automatically adapt to the system theme (OneUI).                                                                      |
| 🟡 **Could Have**  | **(Functional) Security:** The app **could** be locked with a PIN code (managed on the Android side).                                                        |
| 🔴 **Won't Have**  | **(GLOBAL) Banking API Connection:** The app **will not** have any connection to BoursoBank or any aggregator.                                               |
| 🔴 **Won't Have**  | **(GLOBAL) Automatic Import:** The app **will not** import data. All entry is 100% manual.                                                                   |
| 🔴 **Won't Have**  | **(GLOBAL) Cloud Sync:** The app is 100% local and offline.                                                                                                  |
| 🔴 **Won't Have**  | **(GLOBAL) Multi-currency:** The scope is limited to a single currency (e.g., Euro).                                                                         |